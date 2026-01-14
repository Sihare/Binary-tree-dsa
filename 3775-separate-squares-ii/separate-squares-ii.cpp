class Solution {
public:
    struct Event {
        long long y, x1, x2;
        int type;
        bool operator<(const Event& o) const { return y < o.y; }
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<long long> len, xs;

        SegTree(vector<long long>& x) : xs(x) {
            n = xs.size() - 1;
            cnt.assign(4*n, 0);
            len.assign(4*n, 0);
        }

        void pull(int i, int l, int r) {
            if (cnt[i] > 0) len[i] = xs[r] - xs[l];
            else if (l + 1 == r) len[i] = 0;
            else len[i] = len[i*2] + len[i*2+1];
        }

        void upd(int i, int l, int r, int ql, int qr, int v) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[i] += v;
                pull(i,l,r);
                return;
            }
            int m = (l+r)/2;
            upd(i*2,l,m,ql,qr,v);
            upd(i*2+1,m,r,ql,qr,v);
            pull(i,l,r);
        }

        void update(int l, int r, int v) { upd(1,0,n,l,r,v); }
        long long query() { return len[1]; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<long long> xs;

        for (auto&s: squares) {
            long long x=s[0], y=s[1], l=s[2];
            events.push_back({y,x,x+l,1});
            events.push_back({y+l,x,x+l,-1});
            xs.push_back(x);
            xs.push_back(x+l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end());

        SegTree st(xs);

        struct Slab { double y1,y2,w; };
        vector<Slab> slabs;

        long long prevY = events[0].y;
        int i = 0;

        while (i < events.size()) {
            long long y = events[i].y;
            if (y > prevY && st.query() > 0) {
                slabs.push_back({(double)prevY, (double)y, (double)st.query()});
            }
            while (i < events.size() && events[i].y == y) {
                int l = lower_bound(xs.begin(),xs.end(),events[i].x1)-xs.begin();
                int r = lower_bound(xs.begin(),xs.end(),events[i].x2)-xs.begin();
                st.update(l,r,events[i].type);
                i++;
            }
            prevY = y;
        }

        double total = 0;
        for (auto&s: slabs) total += (s.y2-s.y1)*s.w;

        double need = total/2.0;
        double cur = 0;

        for (auto&s: slabs) {
            double slabArea = (s.y2-s.y1)*s.w;
            if (cur + slabArea >= need) {
                return s.y1 + (need-cur)/s.w;
            }
            cur += slabArea;
        }
        return slabs.back().y2;
    }
};